##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SYSCALL_DIR	=	syscall/

SRC		=	get_next_line.c	\
			syscall_asm_generator.c	\

BONUS_SRC	=	$(SYSCALL_DIR)read.s	\
			$(SYSCALL_DIR)write.s	\
			$(SYSCALL_DIR)open.s	\
			$(SYSCALL_DIR)close.s	\
			$(SYSCALL_DIR)stat.s	\
			$(SYSCALL_DIR)fstat.s	\
			$(SYSCALL_DIR)lstat.s	\
			$(SYSCALL_DIR)poll.s	\
			$(SYSCALL_DIR)lseek.s	\
			$(SYSCALL_DIR)mmap.s	\
			$(SYSCALL_DIR)mprotect.s	\
			$(SYSCALL_DIR)munmap.s	\
			$(SYSCALL_DIR)brk.s	\
			$(SYSCALL_DIR)rt_sigaction.s	\
			$(SYSCALL_DIR)rt_sigprocmask.s	\
			$(SYSCALL_DIR)rt_sigreturn.s	\
			$(SYSCALL_DIR)ioctl.s	\
			$(SYSCALL_DIR)pread64.s	\
			$(SYSCALL_DIR)pwrite64.s	\
			$(SYSCALL_DIR)readv.s	\
			$(SYSCALL_DIR)writev.s	\
			$(SYSCALL_DIR)access.s	\
			$(SYSCALL_DIR)pipe.s	\
			$(SYSCALL_DIR)select.s	\
			$(SYSCALL_DIR)sched_yield.s	\
			$(SYSCALL_DIR)mremap.s	\
			$(SYSCALL_DIR)msync.s	\
			$(SYSCALL_DIR)mincore.s	\
			$(SYSCALL_DIR)madvise.s	\
			$(SYSCALL_DIR)shmget.s	\
			$(SYSCALL_DIR)shmat.s	\
			$(SYSCALL_DIR)shmctl.s	\
			$(SYSCALL_DIR)dup.s	\
			$(SYSCALL_DIR)dup2.s	\
			$(SYSCALL_DIR)pause.s	\
			$(SYSCALL_DIR)nanosleep.s	\
			$(SYSCALL_DIR)getitimer.s	\
			$(SYSCALL_DIR)alarm.s	\
			$(SYSCALL_DIR)setitimer.s	\
			$(SYSCALL_DIR)getpid.s	\
			$(SYSCALL_DIR)sendfile.s	\
			$(SYSCALL_DIR)socket.s	\
			$(SYSCALL_DIR)connect.s	\
			$(SYSCALL_DIR)accept.s	\
			$(SYSCALL_DIR)sendto.s	\
			$(SYSCALL_DIR)recvfrom.s	\
			$(SYSCALL_DIR)sendmsg.s	\
			$(SYSCALL_DIR)recvmsg.s	\
			$(SYSCALL_DIR)shutdown.s	\
			$(SYSCALL_DIR)bind.s	\
			$(SYSCALL_DIR)listen.s	\
			$(SYSCALL_DIR)getsockname.s	\
			$(SYSCALL_DIR)getpeername.s	\
			$(SYSCALL_DIR)socketpair.s	\
			$(SYSCALL_DIR)setsockopt.s	\
			$(SYSCALL_DIR)getsockopt.s	\
			$(SYSCALL_DIR)clone.s	\
			$(SYSCALL_DIR)fork.s	\
			$(SYSCALL_DIR)vfork.s	\
			$(SYSCALL_DIR)execve.s	\
			$(SYSCALL_DIR)exit.s	\
			$(SYSCALL_DIR)wait4.s	\
			$(SYSCALL_DIR)kill.s	\
			$(SYSCALL_DIR)uname.s	\
			$(SYSCALL_DIR)semget.s	\
			$(SYSCALL_DIR)semop.s	\
			$(SYSCALL_DIR)semctl.s	\
			$(SYSCALL_DIR)shmdt.s	\
			$(SYSCALL_DIR)msgget.s	\
			$(SYSCALL_DIR)msgsnd.s	\
			$(SYSCALL_DIR)msgrcv.s	\
			$(SYSCALL_DIR)msgctl.s	\
			$(SYSCALL_DIR)fcntl.s	\
			$(SYSCALL_DIR)flock.s	\
			$(SYSCALL_DIR)fsync.s	\
			$(SYSCALL_DIR)fdatasync.s	\
			$(SYSCALL_DIR)truncate.s	\
			$(SYSCALL_DIR)ftruncate.s	\
			$(SYSCALL_DIR)getdents.s	\
			$(SYSCALL_DIR)getcwd.s	\
			$(SYSCALL_DIR)chdir.s	\
			$(SYSCALL_DIR)fchdir.s	\
			$(SYSCALL_DIR)rename.s	\
			$(SYSCALL_DIR)mkdir.s	\
			$(SYSCALL_DIR)rmdir.s	\
			$(SYSCALL_DIR)creat.s	\
			$(SYSCALL_DIR)link.s	\
			$(SYSCALL_DIR)unlink.s	\
			$(SYSCALL_DIR)symlink.s	\
			$(SYSCALL_DIR)readlink.s	\
			$(SYSCALL_DIR)chmod.s	\
			$(SYSCALL_DIR)fchmod.s	\
			$(SYSCALL_DIR)chown.s	\
			$(SYSCALL_DIR)fchown.s	\
			$(SYSCALL_DIR)lchown.s	\
			$(SYSCALL_DIR)umask.s	\
			$(SYSCALL_DIR)gettimeofday.s	\
			$(SYSCALL_DIR)getrlimit.s	\
			$(SYSCALL_DIR)getrusage.s	\
			$(SYSCALL_DIR)sysinfo.s	\
			$(SYSCALL_DIR)ptrace.s	\
			$(SYSCALL_DIR)getuid.s	\
			$(SYSCALL_DIR)syslog.s	\
			$(SYSCALL_DIR)getgid.s	\
			$(SYSCALL_DIR)setuid.s	\
			$(SYSCALL_DIR)setgid.s	\
			$(SYSCALL_DIR)geteuid.s	\
			$(SYSCALL_DIR)getegid.s	\
			$(SYSCALL_DIR)setpgid.s	\
			$(SYSCALL_DIR)getppid.s	\
			$(SYSCALL_DIR)getpgrp.s	\
			$(SYSCALL_DIR)setsid.s	\
			$(SYSCALL_DIR)setreuid.s	\
			$(SYSCALL_DIR)setregid.s	\
			$(SYSCALL_DIR)getgroups.s	\
			$(SYSCALL_DIR)setgroups.s	\
			$(SYSCALL_DIR)setresuid.s	\
			$(SYSCALL_DIR)getresuid.s	\
			$(SYSCALL_DIR)setresgid.s	\
			$(SYSCALL_DIR)getresgid.s	\
			$(SYSCALL_DIR)getpgid.s	\
			$(SYSCALL_DIR)setfsuid.s	\
			$(SYSCALL_DIR)setfsgid.s	\
			$(SYSCALL_DIR)getsid.s	\
			$(SYSCALL_DIR)capget.s	\
			$(SYSCALL_DIR)capset.s	\
			$(SYSCALL_DIR)rt_sigpending.s	\
			$(SYSCALL_DIR)rt_sigtimedwait.s	\
			$(SYSCALL_DIR)rt_sigqueueinfo.s	\
			$(SYSCALL_DIR)rt_sigsuspend.s	\
			$(SYSCALL_DIR)sigaltstack.s	\
			$(SYSCALL_DIR)utime.s	\
			$(SYSCALL_DIR)mknod.s	\
			$(SYSCALL_DIR)uselib.s	\
			$(SYSCALL_DIR)personality.s	\
			$(SYSCALL_DIR)ustat.s	\
			$(SYSCALL_DIR)statfs.s	\
			$(SYSCALL_DIR)fstatfs.s	\
			$(SYSCALL_DIR)sysfs.s	\
			$(SYSCALL_DIR)getpriority.s	\
			$(SYSCALL_DIR)setpriority.s	\
			$(SYSCALL_DIR)sched_setparam.s	\
			$(SYSCALL_DIR)sched_getparam.s	\
			$(SYSCALL_DIR)sched_setscheduler.s	\
			$(SYSCALL_DIR)sched_getscheduler.s	\
			$(SYSCALL_DIR)sched_get_priority_max.s	\
			$(SYSCALL_DIR)sched_get_priority_min.s	\
			$(SYSCALL_DIR)sched_rr_get_interval.s	\
			$(SYSCALL_DIR)mlock.s	\
			$(SYSCALL_DIR)munlock.s	\
			$(SYSCALL_DIR)mlockall.s	\
			$(SYSCALL_DIR)munlockall.s	\
			$(SYSCALL_DIR)vhangup.s	\
			$(SYSCALL_DIR)modify_ldt.s	\
			$(SYSCALL_DIR)pivot_root.s	\
			$(SYSCALL_DIR)_sysctl.s	\
			$(SYSCALL_DIR)prctl.s	\
			$(SYSCALL_DIR)arch_prctl.s	\
			$(SYSCALL_DIR)adjtimex.s	\
			$(SYSCALL_DIR)setrlimit.s	\
			$(SYSCALL_DIR)chroot.s	\
			$(SYSCALL_DIR)sync.s	\
			$(SYSCALL_DIR)acct.s	\
			$(SYSCALL_DIR)settimeofday.s	\
			$(SYSCALL_DIR)mount.s	\
			$(SYSCALL_DIR)umount2.s	\
			$(SYSCALL_DIR)swapon.s	\
			$(SYSCALL_DIR)swapoff.s	\
			$(SYSCALL_DIR)reboot.s	\
			$(SYSCALL_DIR)sethostname.s	\
			$(SYSCALL_DIR)setdomainname.s	\
			$(SYSCALL_DIR)iopl.s	\
			$(SYSCALL_DIR)ioperm.s	\
			$(SYSCALL_DIR)create_module.s	\
			$(SYSCALL_DIR)init_module.s	\
			$(SYSCALL_DIR)delete_module.s	\
			$(SYSCALL_DIR)get_kernel_syms.s	\
			$(SYSCALL_DIR)query_module.s	\
			$(SYSCALL_DIR)quotactl.s	\
			$(SYSCALL_DIR)nfsservctl.s	\
			$(SYSCALL_DIR)getpmsg.s	\
			$(SYSCALL_DIR)putpmsg.s	\
			$(SYSCALL_DIR)afs_syscall.s	\
			$(SYSCALL_DIR)tuxcall.s	\
			$(SYSCALL_DIR)security.s	\
			$(SYSCALL_DIR)gettid.s	\
			$(SYSCALL_DIR)readahead.s	\
			$(SYSCALL_DIR)setxattr.s	\
			$(SYSCALL_DIR)lsetxattr.s	\
			$(SYSCALL_DIR)fsetxattr.s	\
			$(SYSCALL_DIR)getxattr.s	\
			$(SYSCALL_DIR)lgetxattr.s	\
			$(SYSCALL_DIR)fgetxattr.s	\
			$(SYSCALL_DIR)listxattr.s	\
			$(SYSCALL_DIR)llistxattr.s	\
			$(SYSCALL_DIR)flistxattr.s	\
			$(SYSCALL_DIR)removexattr.s	\
			$(SYSCALL_DIR)lremovexattr.s	\
			$(SYSCALL_DIR)fremovexattr.s	\
			$(SYSCALL_DIR)tkill.s	\
			$(SYSCALL_DIR)time.s	\
			$(SYSCALL_DIR)futex.s	\
			$(SYSCALL_DIR)sched_setaffinity.s	\
			$(SYSCALL_DIR)sched_getaffinity.s	\
			$(SYSCALL_DIR)set_thread_area.s	\
			$(SYSCALL_DIR)io_setup.s	\
			$(SYSCALL_DIR)io_destroy.s	\
			$(SYSCALL_DIR)io_getevents.s	\
			$(SYSCALL_DIR)io_submit.s	\
			$(SYSCALL_DIR)io_cancel.s	\
			$(SYSCALL_DIR)get_thread_area.s	\
			$(SYSCALL_DIR)lookup_dcookie.s	\
			$(SYSCALL_DIR)epoll_create.s	\
			$(SYSCALL_DIR)epoll_ctl_old.s	\
			$(SYSCALL_DIR)epoll_wait_old.s	\
			$(SYSCALL_DIR)remap_file_pages.s	\
			$(SYSCALL_DIR)getdents64.s	\
			$(SYSCALL_DIR)set_tid_address.s	\
			$(SYSCALL_DIR)restart_syscall.s	\
			$(SYSCALL_DIR)semtimedop.s	\
			$(SYSCALL_DIR)fadvise64.s	\
			$(SYSCALL_DIR)timer_create.s	\
			$(SYSCALL_DIR)timer_settime.s	\
			$(SYSCALL_DIR)timer_gettime.s	\
			$(SYSCALL_DIR)timer_getoverrun.s	\
			$(SYSCALL_DIR)timer_delete.s	\
			$(SYSCALL_DIR)clock_settime.s	\
			$(SYSCALL_DIR)clock_gettime.s	\
			$(SYSCALL_DIR)clock_getres.s	\
			$(SYSCALL_DIR)clock_nanosleep.s	\
			$(SYSCALL_DIR)exit_group.s	\
			$(SYSCALL_DIR)epoll_wait.s	\
			$(SYSCALL_DIR)epoll_ctl.s	\
			$(SYSCALL_DIR)tgkill.s	\
			$(SYSCALL_DIR)utimes.s	\
			$(SYSCALL_DIR)vserver.s	\
			$(SYSCALL_DIR)mbind.s	\
			$(SYSCALL_DIR)set_mempolicy.s	\
			$(SYSCALL_DIR)get_mempolicy.s	\
			$(SYSCALL_DIR)mq_open.s	\
			$(SYSCALL_DIR)mq_unlink.s	\
			$(SYSCALL_DIR)mq_timedsend.s	\
			$(SYSCALL_DIR)mq_timedreceive.s	\
			$(SYSCALL_DIR)mq_notify.s	\
			$(SYSCALL_DIR)mq_getsetattr.s	\
			$(SYSCALL_DIR)kexec_load.s	\
			$(SYSCALL_DIR)waitid.s	\
			$(SYSCALL_DIR)add_key.s	\
			$(SYSCALL_DIR)request_key.s	\
			$(SYSCALL_DIR)keyctl.s	\
			$(SYSCALL_DIR)ioprio_set.s	\
			$(SYSCALL_DIR)ioprio_get.s	\
			$(SYSCALL_DIR)inotify_init.s	\
			$(SYSCALL_DIR)inotify_add_watch.s	\
			$(SYSCALL_DIR)inotify_rm_watch.s	\
			$(SYSCALL_DIR)migrate_pages.s	\
			$(SYSCALL_DIR)openat.s	\
			$(SYSCALL_DIR)mkdirat.s	\
			$(SYSCALL_DIR)mknodat.s	\
			$(SYSCALL_DIR)fchownat.s	\
			$(SYSCALL_DIR)futimesat.s	\
			$(SYSCALL_DIR)newfstatat.s	\
			$(SYSCALL_DIR)unlinkat.s	\
			$(SYSCALL_DIR)renameat.s	\
			$(SYSCALL_DIR)linkat.s	\
			$(SYSCALL_DIR)symlinkat.s	\
			$(SYSCALL_DIR)readlinkat.s	\
			$(SYSCALL_DIR)fchmodat.s	\
			$(SYSCALL_DIR)faccessat.s	\
			$(SYSCALL_DIR)pselect6.s	\
			$(SYSCALL_DIR)ppoll.s	\
			$(SYSCALL_DIR)unshare.s	\
			$(SYSCALL_DIR)set_robust_list.s	\
			$(SYSCALL_DIR)get_robust_list.s	\
			$(SYSCALL_DIR)splice.s	\
			$(SYSCALL_DIR)tee.s	\
			$(SYSCALL_DIR)sync_file_range.s	\
			$(SYSCALL_DIR)vmsplice.s	\
			$(SYSCALL_DIR)move_pages.s	\
			$(SYSCALL_DIR)utimensat.s	\
			$(SYSCALL_DIR)epoll_pwait.s	\
			$(SYSCALL_DIR)signalfd.s	\
			$(SYSCALL_DIR)timerfd_create.s	\
			$(SYSCALL_DIR)eventfd.s	\
			$(SYSCALL_DIR)fallocate.s	\
			$(SYSCALL_DIR)timerfd_settime.s	\
			$(SYSCALL_DIR)timerfd_gettime.s	\
			$(SYSCALL_DIR)accept4.s	\
			$(SYSCALL_DIR)signalfd4.s	\
			$(SYSCALL_DIR)eventfd2.s	\
			$(SYSCALL_DIR)epoll_create1.s	\
			$(SYSCALL_DIR)dup3.s	\
			$(SYSCALL_DIR)pipe2.s	\
			$(SYSCALL_DIR)inotify_init1.s	\
			$(SYSCALL_DIR)preadv.s	\
			$(SYSCALL_DIR)pwritev.s	\
			$(SYSCALL_DIR)rt_tgsigqueueinfo.s	\
			$(SYSCALL_DIR)perf_event_open.s	\
			$(SYSCALL_DIR)recvmmsg.s	\
			$(SYSCALL_DIR)fanotify_init.s	\
			$(SYSCALL_DIR)fanotify_mark.s	\
			$(SYSCALL_DIR)prlimit64.s	\
			$(SYSCALL_DIR)name_to_handle_at.s	\
			$(SYSCALL_DIR)open_by_handle_at.s	\
			$(SYSCALL_DIR)clock_adjtime.s	\
			$(SYSCALL_DIR)syncfs.s	\
			$(SYSCALL_DIR)sendmmsg.s	\
			$(SYSCALL_DIR)setns.s	\
			$(SYSCALL_DIR)getcpu.s	\
			$(SYSCALL_DIR)process_vm_readv.s	\
			$(SYSCALL_DIR)process_vm_writev.s	\
			$(SYSCALL_DIR)kcmp.s	\
			$(SYSCALL_DIR)finit_module.s	\
			$(SYSCALL_DIR)sched_setattr.s	\
			$(SYSCALL_DIR)sched_getattr.s	\
			$(SYSCALL_DIR)renameat2.s	\
			$(SYSCALL_DIR)seccomp.s	\
			$(SYSCALL_DIR)getrandom.s	\
			$(SYSCALL_DIR)memfd_create.s	\
			$(SYSCALL_DIR)kexec_file_load.s	\
			$(SYSCALL_DIR)bpf.s	\
			$(SYSCALL_DIR)execveat.s	\
			$(SYSCALL_DIR)userfaultfd.s	\
			$(SYSCALL_DIR)membarrier.s	\
			$(SYSCALL_DIR)mlock2.s	\
			$(SYSCALL_DIR)copy_file_range.s	\
			$(SYSCALL_DIR)preadv2.s	\
			$(SYSCALL_DIR)pwritev2.s	\
			$(SYSCALL_DIR)pkey_mprotect.s	\
			$(SYSCALL_DIR)pkey_alloc.s	\
			$(SYSCALL_DIR)pkey_free.s	\
			$(SYSCALL_DIR)statx.s

#BONUS_SRC		+= $(SYSCALL_DIR)times.s

OBJ		=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.s=.o)

CFLAGS		=	-W -Wall -Wextra -Werror	\
			-g

LDFLAGS		=	-shared

NAME		=	syscall_asm_generator
BONUS_NAME	=	libsyscall_asm.so

all:		generator asm

generator:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		./$(NAME)

asm:		$(BONUS_OBJ)
		$(LD) -o $(BONUS_NAME) $(BONUS_OBJ) $(LDFLAGS)

%.o:		%.s
		nasm -felf64 $< -o $@

clean:
		@rm -f $(OBJ)
		@rm -f $(BONUS_OBJ)

fclean:		clean
		@rm -f $(NAME)
		@rm -f $(BONUS_NAME)

re:		fclean generator asm

.PHONY:		all clean fclean re generator asm
