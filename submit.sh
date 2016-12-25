#!/bin/bash
git pull
rm *.o
git add .
echo $(date)
git commit -m 'Daily commit from ubuntu $(date)'
git push origin master
