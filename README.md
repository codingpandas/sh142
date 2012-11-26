sh142
=====
CMPE 142 Unix Shell

Known Bugs
=====
- Change Directory (cd) is not fully working
- Error Handling missing for certain commands

Done
=====
- User should be able to dynamically set a persistent executable path: PATH=/home/usr/myname:/usr/bin
- Load environmental variables from file after setting them and refresh the environment
- User should be able to dynamically set a persistent data file path: DATA=/data/files:/home/usr/myname
- User should be able to check the exit status of the last few commands by executing $?1, $?2, …

Partially Done
====
- User should be able to set and unset shell variables and use them in command lines: MYPATH=/mydir Cmd1 $MYPATH/file
- Shell must connect to remote shells and be able to support local and remote execution.
- User should be able to iterate the execution of one or more commands as follows:For (n=0;n < MAX; n++) Com1;Com2;…forend

To Do List
====
- User should be able to run commands on the executable Path
- User should be able to run a command with an argument being a data file as follows, and the shell should automatically locate the file in the data path (DATA): mycommand #D:datafileargument
- User should be able to redirect standard input, output, and error to files using the <, >, and 2> symbols.
- User should be able to pipeline a number of commands using the following syntax:Cmd1 | cmd2 | cmd3…
- User should be able to execute commands conditionally: !cmd1 && cmd2 || cmd3…
- User should be able to specify commands to run in the background:Cmd1 &
- User should be able to bring background commands back to foreground.
- User should be able to query background jobs.
- User should be able to specify maximum amount of memory and CPU utilization that a command may use before being terminated by the shell:CPUMAX=99:200 (programs can run at most 200 seconds with CPU utilization of 99% or more) MEMMAX=50M:360 (programs cannot exceede 50Megabytes for more than 360 seconds) TIMEMAX=250 (programs can’t run for more than 250 seconds)
