#!/bin/bash

# Build Signum 3.0 firmware
echo "############################################"
echo "####    Building Signum 3.0 firmware    ####"
echo "############################################"
make clean >/dev/null 2>&1
echo "#         Building custom firware          #"
if ! make signum/3_0/elitec:my_keymap 1>/dev/null;
then
  exit 1
fi
make clean >/dev/null 2>&1
echo "#         Building default firware         #"
if ! make signum/3_0/elitec:default 1>/dev/null;
then
  exit 1
fi
echo -e "############################################\n"

# Build Crkbd rev1 firmware
echo "############################################"
echo "####     Build Crkbd rev1 firmware      ####"
echo "############################################"
make clean >/dev/null 2>&1
echo "#         Building custom firware          #"
if ! make crkbd/rev1:my_keymap 1>/dev/null;
then
  exit 2
fi
make clean >/dev/null 2>&1
echo "#         Building default firware         #"
if ! make crkbd/rev1:default 1>/dev/null;
then
  exit 2
fi
echo -e "############################################\n"

# Build Iris rev4 firmware
echo "############################################"
echo "####      Build Iris rev4 firmware      ####"
echo "############################################"
make clean >/dev/null 2>&1
echo "#         Building custom firware          #"
if ! make keebio/iris/rev4:my_keymap 1>/dev/null;
then
  exit 3
fi
make clean >/dev/null 2>&1
echo "#         Building default firware         #"
if ! make keebio/iris/rev4:default 1>/dev/null;
then
  exit 3
fi
echo -e "############################################\n"

# Build Quefrency rev1 firmware
echo "############################################"
echo "#      Build Quefrency rev1 firmware       #"
echo "############################################"
make clean >/dev/null 2>&1
echo "#         Building custom firware          #"
if ! make keebio/quefrency/rev1:my_keymap 1>/dev/null;
then
  exit 4
fi
make clean >/dev/null 2>&1
echo "#         Building default firware         #"
if ! make keebio/quefrency/rev1:default 1>/dev/null;
then
  exit 4
fi
echo -e "############################################\n"

# Build Dactyl-Manuform firmware
echo "############################################"
echo "####   Build Dactyl-Manuform firmware   ####"
echo "############################################"
make clean >/dev/null 2>&1
echo "#          Building custom firware         #"
if ! make handwired/dactyl_manuform/5x6:my_keymap 1>/dev/null;
then
  exit 5
fi
make clean >/dev/null 2>&1
echo "#          Building default firware        #"
echo "############################################"
if ! make handwired/dactyl_manuform/5x6:default 1>/dev/null;
then
  exit 5
fi
