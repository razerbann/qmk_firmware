#!/bin/bash

git fetch origin
git fetch upstream

# Update master branch from qmk/qmk_firware base repository
echo "############################################"
echo "#### Updating code from base repository ####"
echo "############################################"
git rebase upstream/master
git push origin master -f

# Build Signum 3.0 firmware
echo "############################################"
echo "####    Building Signum 3.0 firmware    ####"
echo "############################################"
rm -rf .build
make clean
if ! make signum/3_0/elitec:my_keymap;
then
  exit 1
fi
make clean
if ! make signum/3_0/elitec:default;
then
  exit 1
fi

# Build Crkbd rev1 firmware
echo "############################################"
echo "####     Build Crkbd rev1 firmware      ####"
echo "############################################"
rm -rf .build
make clean
if ! make crkbd/rev1:my_keymap;
then
  exit 2
fi
make clean
if ! make crkbd/rev1:default;
then
  exit 2
fi

# Build Iris rev4 firmware
echo "############################################"
echo "####      Build Iris rev4 firmware      ####"
echo "############################################"
rm -rf .build
make clean
if ! make keebio/iris/rev4:my_keymap;
then
  exit 3
fi
make clean
if ! make keebio/iris/rev4:default;
then
  exit 3
fi
# Build Quefrency rev1 firmware
echo "############################################"
echo "####   Build Quefrency rev1 firmware    ####"
echo "############################################"
rm -rf .build
make clean
if ! make keebio/quefrency/rev1:my_keymap;
then
  exit 4
fi
make clean
if ! make keebio/quefrency/rev1:default;
then
  exit 4
fi

# Build Dactyl-Manuform firmware
echo "#############################################"
echo "####   Build Dactyl-Manuform firmware    ####"
echo "#############################################"
rm -rf .build
make clean
if ! make handwired/dactyl_manuform/5x6:my_keymap;
then
  exit 5
fi
make clean
if ! make handwired/dactyl_manuform/5x6:default;
then
  exit 5
fi
