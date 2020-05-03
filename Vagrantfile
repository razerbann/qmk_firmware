# -*- mode: ruby -*-
# vi: set ft=ruby :

#################################
# Prerequisites
#################################
# You need to have installed Vagrant and have installed the following plugins:
# - vagrant-cachier
# - vagrant-hostmanager
# - vagrant-share
# - vagrant-vbguest
# To install the plugins, you can run the following command:
# $ vagrant plugin install vagrant-cachier vagrant-hostmanager vagrant-share vagrant-vbguest

#################################
# General project settings
#################################

# The project name is base for directories, hostname and alike
project_name = "qmk"

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure(2) do |config|

    # The most common configuration options are documented and commented below.
    # For a complete reference, please see the online documentation at
    # https://docs.vagrantup.com.
    config.vbguest.auto_update = false
    # Disable default syncing
    config.vm.synced_folder ".", "/vagrant", disabled: true
    # Always use Vagrants insecure key
    config.ssh.insert_key = false

    config.vm.define project_name do |machine|
        # Every Vagrant development environment requires a box. You can search for
        # boxes at https://atlas.hashicorp.com/search.
        machine.vm.box = "geerlingguy/debian10"

        # Share an additional folder to the guest VM. The first argument is
        # the path on the host to the actual folder. The second argument is
        # the path on the guest to mount the folder. And the optional third
        # argument is a set of non-required options.
        machine.vm.synced_folder "./" , "/qmk_firmware",
            id: project_name,
            mount_options: ["dmode=755", "fmode=755"]

        # Vagrant VM hostname
        machine.vm.hostname = project_name

        # Provider-specific configuration so you can fine-tune various
        # backing providers for Vagrant. These expose provider-specific options.
        # Example for VirtualBox:
        machine.vm.provider "virtualbox" do |vb|
            # Customize the VM name
            vb.name = "VM to flash QMK firmware into ProMicro"
            # Display the VirtualBox GUI when booting the machine
            vb.gui = false
            # Customize the amount of memory on the VM:
            vb.memory = "256"
            # Customize the number of cpus on the VM:
            vb.cpus = 1

            vb.customize ["modifyvm", :id, "--usb", "on"]
            vb.customize ["modifyvm", :id, "--usbehci", "on"]
            # Please rewrite according to your environment. VID/PID is required.
            vb.customize ["usbfilter", "add", "0",
                         "--target", :id,
                         "--name", "Arduino Micro (writable)",
                         "--vendorid", "2341",
                         "--productid", "0036",
                         "--remote", "no"]
            vb.customize ["usbfilter", "add", "1",
                         "--target", :id,
                         "--name", "Arduino Micro",
                         "--vendorid", "2341",
                         "--productid", "8036",
                         "--remote", "no"]
        end

        # Install build tools
        machine.vm.provision "shell", privileged: false, inline: <<-SHELL
        echo 'export PATH=/home/vagrant/.local/bin:${PATH}' >> /home/vagrant/.bashrc
        source /home/vagrant/.bashrc
        sudo apt-get update
        sudo apt-get -y install python3-pip avrdude
        chmod +x /qmk_firmware/util/qmk_install.sh
        /qmk_firmware/util/qmk_install.sh
        SHELL
    end

    config.vm.post_up_message = <<-EOT
Log into the environment using 'vagrant ssh'. QMK directory synchronized with
host is located at /qmk_firmware
To compile the .hex files use make command inside this directory, e.g.
    $ cd /qmk_firmware
    $ sudo make handwired/dactyl_manuform/5x6:my_keymap
    $ sudo make crkbd/rev1:my_keymap
To compule the .hex files and flash it into the Pro Micro
    $ cd /qmk_firmware
    $ sudo make handwired/dactyl_manuform/5x6:my_keymap:avrdude
    $ sudo make crkbd/rev1:my_keymap:avrdude
EOT
  end
