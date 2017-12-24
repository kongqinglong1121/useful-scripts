#!/bin/bash
# @Function
# Run command and put output to system clipper.
#
# @Usage
#   $ c echo "hello world!"
#   $ echo "hello world!" | c
#
# @online-doc https://github.com/oldratlee/useful-scripts/blob/master/docs/shell.md#beer-c
# @author Jerry Lee (oldratlee at gmail dot com)

copy() {
    case "`uname`" in
    Darwin*)
        pbcopy ;;
    CYGWIN*|MINGW*)
        clip ;;
    *)
        xsel -b ;;
    esac
}

teeAndCopy() {
    tee >(content="$(cat)"; echo -n "$content" | copy)
}

[ $# -eq 0 ] && teeAndCopy ||
                "$@" | teeAndCopy
