#! /bin/bash

if ! [[ -d src ]]; then
    echo "The src/ dir does not exist."
    echo "Your xv6 code should be in the src/ directory"
    echo "to enable the automatic tester to work."
    exit 1
fi
rm -r tests;
mkdir tests;
cp -r test/vm/* tests;
./tester/run-tests.sh $*;