# This only concerns people wanting to flash the firmware from a macOS environment running Catalina
## Prerequisites
First, you need to have VirtualBox & VirtualBox Extension Pack installed from the official website: https://www.virtualbox.org/wiki/Downloads.
Next, you'll need to install Vagrant. You can either download the latest version from the official website: https://www.vagrantup.com/downloads.html or from Homebrew using the following command:
`$ brew cask install vagrant`

Also, you'll need to have the following plugins installed:
- vagrant-cachier
- vagrant-share
- vagrant-vbguest
To install the plugins, you can run the following command:
`$ vagrant plugin install vagrant-cachier vagrant-share vagrant-vbguest`

## Compiling and flashing
You need to edit the Vagrantfile and update the vendorid & productid of the usbfilter to match your ProMicro.
The first usbfilter "Arduino Micro (writable)" is for when your ProMicro is in reset mode, and the second one "Arduino Micro" is for when the ProMicro is simply connected to the computer.
You can find those information easily by using the Arduino IDE: https://www.arduino.cc/en/Main/Software

After you update the vendorid & productid for the two usbfilters, you're ready to can start the VM.
Open a terminal in this directory and run `$ vagrant up`
Now, we're ready to compile the .hex file (firmware).
Log into the environment using 'vagrant ssh'.
QMK directory synchronized with host is located at /qmk_firware
To compile the .hex files use make command inside this directory, e.g.
   $ cd /qmk_firware
   $ sudo make crkbd/rev1:my_keymap
To compule the .hex files and flash it into the Pro Micro
    $ cd /qmk_firware
    $ sudo make crkbd/rev1:my_keymap:avrdude

In order to stop the VM, you can run: `$ vagrant halt`
If you want to delete the VM, you can run: `$ vagrant destroy -f`