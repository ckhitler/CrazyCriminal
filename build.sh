#!/bin/bash


[ ! -d bin ] && mkdir bin
gcc src/core_dump.c -o bin/core_dump
gcc src/cpu_load.c -o bin/cpu_load
gcc src/docker_max.c -o bin/docker_max
gcc src/file_max.c -o bin/file_max
gcc src/fork_crazy.c -o bin/fork_crazy
gcc src/iops_load.c -o bin/iops_load
gcc src/iptables_drop.c -o bin/iptables_drop
gcc src/memory_crazy.c -o bin/memory_crazy
gcc src/memory_leak.c -o bin/memory_leak
gcc src/net_delay.c -o bin/net_delay
gcc src/net_down.c -o bin/net_down
gcc src/net_loss.c -o bin/net_loss
gcc src/sched_fifo.c -o bin/sched_fifo -pthread
gcc src/signal_pending.c -o bin/signal_pending
gcc src/socket_connect.c -o bin/socket_connect -pthread
gcc src/thread_crazy.c -o bin/thread_crazy -pthread
gcc src/write_log.c -o bin/write_log
