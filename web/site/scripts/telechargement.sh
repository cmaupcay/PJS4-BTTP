#!/bin/bash

if [ -z ${1} ]
then
	echo "Veuillez préciser une URL."
	exit -1
fi

wget $1 > /dev/null
