#!/bin/sh

git filter-branch --env-filter '
OLD_USERNAME="unknown"
CORRECT_NAME="lonelam"
CORRECT_EMAIL="laizenan@gmail.com"
if [ "$GIT_COMMITTER_NAME" = "$OLD_USERNAME" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_NAME" = "$OLD_USERNAME" ]
then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags

