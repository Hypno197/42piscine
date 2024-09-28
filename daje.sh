#!/bin/bash

echo "Pronto?"
read message
git add .
git commit -m"${message}"
if [ -n "$(git status - porcelain)" ];
then
 echo "Guarda che hai già pushato"
else
 git status
 echo "Sto a pusha!!!"
 git push -u origin master
fi
