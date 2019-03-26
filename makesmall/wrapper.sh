#!/bin/bash
# small.sh

printf "Start time: "; /bin/date
printf "Job is running on node: "; /bin/hostname
printf "Job running as user: "; /usr/bin/id
printf "Job is running in directory: "; /bin/pwd
#First, setup the CMS environment

./small $@

printf "End time: "; /bin/date
