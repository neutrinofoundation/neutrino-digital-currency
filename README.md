Neutrinocoin integration/staging tree
================================

http://www.neutrinocoin.org

* Copyright (c) 2009-2013 Bitcoin Developers
* Copyright (c) 2011-2013 Litecoin Developers
* Copyright (c) 2013-2014 Neutrinocoin Developers

What is Neutrinocoin?
----------------

Neutrinocoin is a version of Litecoin that provides extra privacy features.
 - 2.5 minute block targets
 - during the first 3 months, subsidy is 3992 coins per block, reduced thereafter to result in 1.1% annual growth.
 - 210 million coins created in the first 3 months, increasing 1.1% thereafter
 - 12 blocks to retarget difficulty

For more information, see http://www.neutrinocoin.org.

License
-------

Neutrinocoin is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Neutrinocoin
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter should explain their case by opening an issue.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/neutrinocoin/neutrinocoin/tags) are created
regularly to indicate new official, stable release versions of Neutrinocoin.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./neutrinocoin-qt_test

