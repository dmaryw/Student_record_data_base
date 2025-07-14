outfile:main.o add_begin.o  del_s.o del_all.o  print.o rev_print.o save.o  count.o modify.o sort.o
	cc main.c del_s.c add_begin.c  del_all.c print.c rev_print.c save.c  count.c modify.c sort.c -o outfile
main.o:main.c
	cc -c main.c
add_begin.o:add_begin.c
	cc -c add_begin.c
print.o:print.c
	cc -c print.c
save.o:save.c
	cc -c save.c
rev_print.o:rev_print.c
	cc -c rev_print.c
count.o:count.c
	cc -c count.c
del_s.o:del_s.c
	cc -c del_s.c
delete_all.o:del_all.c
	cc -c del_all.c
modify.o:modify.c
	cc -c modify.c
sort.o:sort.c
	cc -c sort.c
