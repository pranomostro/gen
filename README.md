Introduction
============

gen is a utility similar to seq, but for characters.
For example:

	gen z

prints the alphabet in lower case, all letters from 'a' to 'z',
separated by newlines.

	gen 17576

prints:

	aaa
	aab
	aac
	[lines cut out]
	zzx
	zzy
	zzz

It is okay for generating test data, and it is required by
[mg](https://www.github.com/scharlatan/mg)

Requirements
------------

make and a c89 compiler are needed, as well as
some standard unix tools. You should be fine.

Installation
------------

	make install

should install gen to /usr/local if not
configured otherwise.

License
-------

It's MIT! Cheer!
