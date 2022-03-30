#!/bin/bash

set -eo pipefail

current_branch = $(git rev-parse --abbrev-ref HEAD)

if ["$current_branch" != master ] && [ "$current_branch" != main ]; then
	echo WARNING:VOTRE BRANCHE N'EST NI main NI master.
fi

if [ -z "$1" ]; then
	echo ERROR: Veuillez préciser un ticket prefixe
	exit 1
fi

if [ -z "$2" ]; then
	echo ERROR: AJoutez une description
	exit 1
fi

prefixe_ticket=$1
description=$2
name=$(echo "$description" | tr '[:upper:]' '[:lower:]' | tr ' ' '-')
commit_message="${prefixe_ticket} ${description}"

git checkout -b "$prefixe_ticket"-"name"
git add .
git commit -m "commit_message"
git push -u origin "$prefixe_ticket"- "name"
