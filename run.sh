#!/bin/bash

while true
do
  case "$[ 1 + $[ RANDOM % 16 ]]" in
    1) echo "core_dump" && bin/core_dump
       ;;
    2) echo 'cpu_load' && bin/cpu_load
       ;;
    3) echo 'docker_max' && bin/docker_max
       ;;
    4) echo 'file_max' && bin/file_max
       ;;
    5) echo 'fork_crazy' && bin/fork_crazy
       ;;
    6) echo 'iops_load' && bin/iops_load
       ;;
    7) echo 'iptables_drop' && bin/iptables_drop
       ;;
    8) echo 'memory_crazy' && bin/memory_crazy
       ;;
    9) echo 'net_delay' && bin/net_delay eth1
       ;;
    10) echo 'net_down' && bin/net_down eth1
       ;;
    11) echo 'net_loss' && bin/net_loss eth1
       ;;
    12) echo 'sched_fifo' && bin/sched_fifo
       ;;
    13) echo 'signal_pending' && bin/signal_pending
       ;;
    14) echo 'socket_connect' && bin/socket_connect
       ;;
    15) echo 'thread_crazy' && bin/thread_crazy
       ;;
    16) echo 'write_log' && bin/write_log
       ;;
  esac
done
