string s;

/*Return Statement*/ fun(int ind, bool last,/* there can be so many arguments based on properties*/ ) {

	// Base Condition
	if (ind == s.size()) {
		return;
	}

  // If last Branch or not.

	int till = (last == true) ? (s[ind] - '0') : 9;

  //Placing Digits at ind position. we have choices from 0...till
	for (int i = 0; i <= till ; i++) {
		fun((ind + 1), (last && (i == till)), /* All arguments*/);
	}
}


int solve(int _n){
	//initialised DP Table here.
	s = to_string(_n);
//function fun iterate through all the numbers from 0 till _n. using recursion tree.
	/*Return Statement*/ fun(0,true,/*All Arguments Needed*/);
}
