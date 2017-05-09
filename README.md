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
	#[lines cut out]
	zzx
	zzy
	zzz

gen can be used for generating test data or generic filenames.

Installation
------------

	make install

should install gen to /usr/local if not
configured otherwise.

License
-------

[MIT license](./LICENSE).
