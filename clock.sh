#bash script for feeding clock times into the clock program on the command line
#!/bin/bash

while :
do
    date +%R:%S
    sleep 1
done
