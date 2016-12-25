#!/bin/bash
git pull
rm *.o
git add .
git commit -m 'Daily commit from ubuntu $(date)'
git push origin master
