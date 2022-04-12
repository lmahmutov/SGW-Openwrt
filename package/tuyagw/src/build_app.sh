#!/bin/sh

APP_BIN_NAME=

SH_DESC="\
\r\n\
Usage: bash build_app.sh <project>\r\n\
\r\n\
[project]: \r\n\
`ls demos`  \r\n\
"

if [ -z "$1" ]; then
    echo $SH_DESC
    exit 1
fi

APP_BIN_NAME=$1

for d in `ls demos`; do
    if [ "$d"x = "$APP_BIN_NAME"x ]; then
        make APP_BIN_NAME=$APP_BIN_NAME build_app
        exit 0
    fi
done

echo "$APP_BIN_NAME is not found"

exit 1
