test_msitest_one {

    *err = errormsg(
               msitest_one(
                   "INPUT_STRING",
                   17,
                   12.8 ),
                   *msg );
    if( 0 != *err ) {
        writeLine( "stdout", "Error - [*msg], *err" );
    } else {
        writeLine( "stdout", "success?" );
    }

}

INPUT null
OUTPUT ruleExecOut

