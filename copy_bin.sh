#!/bin/sh
cp bin/*.exe bin/*.dll ../cuckoo/data/monitor/latest/
cp bin/logs_dispatcher.exe bin/*.sys ../cuckoo/analyzer/windows/bin/
rm ../cuckoo/data/monitor/latest/logs_dispatcher.exe

