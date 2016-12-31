#!/bin/bash
git pull
git add .
echo $(date)
git commit -m "Daily commit $(date)"
git push origin master
