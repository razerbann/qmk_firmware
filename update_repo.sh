#!/bin/bash

echo "############################################"
echo "####  Updating code from my repository  ####"
echo "############################################"
if ! git fetch origin 1>/dev/null;
then
  exit 1
fi

echo "############################################"
echo "#### Updating code from base repository ####"
echo "############################################"
if ! git fetch upstream 1>/dev/null;
then
  exit 2
fi

echo "############################################"
echo "#### Rebase upstream/master onto origin ####"
echo "############################################"
if ! git rebase upstream/master 1>/dev/null;
then
  exit 1
else
  git submodule update
fi

echo "############################################"
echo "####   Push the code to origin/master   ####"
echo "############################################"
if ! git push origin master -f 1>/dev/null;
then
  exit 2
fi
echo
