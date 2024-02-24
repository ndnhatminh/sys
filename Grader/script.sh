#!/bin/sh

usage() { echo "Usage: $0 [-d | -p]" 1>&2; exit 0; }

[ $# -eq 0 ] && usage

# if [ getopts ":dp" opt; ]
# then 
#     echo "Must provide option. Valid option: -d (development), -p (production)"
#     exit
# fi

while getopts ":dp" opt; do
  case $opt in
    d)
    #   echo "-d (development) was triggered!" >&2
      flask run & flask init-consumer-sug && fg
      exit
      ;;
    p)
    #   echo "-p (production) was triggered!" >&2
      gunicorn wsgi:app && fg
      exit
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit
      ;;
  esac
done

