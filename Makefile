all: bySeventeen recurse grades

bySeventeen: bySeventeen.c
	gcc -g -o $@.o $<

recurse: recurse.c
	gcc -g -o $@.o $<

grades: grades.c
	gcc -g -o $@.o $<

clean:
	rm -f bySeventeen.o recurse.o grades.o
