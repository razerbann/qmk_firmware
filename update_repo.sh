#!/bin/bash

git checkout master
git fetch upstream
git submodule update
git rebase upstream/master
git push origin master -f
