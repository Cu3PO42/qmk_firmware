#!/bin/bash

# Resolve the first argument before we change directories
SOURCE_BALL=$(readlink -f $1)
# Change to the top level of the Git repository
cd "$(dirname "$0")"
cd $(git rev-parse --show-toplevel)
# First save pending work
oldsha=$(git rev-parse -q --verify refs/stash)
git stash push -m "Temp: Update script"
newsha=$(git rev-parse -q --verify refs/stash)
if [ "$oldsha" = "$newsha" ]; then
    made_stash_entry=false
else
    made_stash_entry=true
fi
# Now apply our changes to the Neo2 base branch
BRANCH=$(git branch --show-current)
git checkout neo2-base
cd ./keyboards/moonlander/keymaps/neo2
unzip -jo $SOURCE_BALL 'moonlander_neo-2_source/*'
git add ./*
if [ -z "$2" ]; then
    git commit --allow-empty
else
    git commit --allow-empty -m "$2"
fi
NEW_COMMIT=$(git rev-parse HEAD)
# Return to our previous branch and copy work
git checkout $BRANCH
if [ "$BRANCH" != "neo2-base" ]; then
    git cherry-pick --allow-empty $NEW_COMMIT
fi
if $made_stash_entry; then
    git stash pop
fi