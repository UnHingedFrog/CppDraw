// SPDX-License-Identifier: MIT
pragma solidity >=0.4.25 <0.7.0;

import "../ABDKMath64x64.sol";

// This is just a simple example of a coin-like contract.
// It is not standards compatible and cannot be expected to talk to other
// coin/token contracts. If you want to create a standards-compliant
// token, see: https://github.com/ConsenSys/Tokens. Cheers!

// UnHingedFrog

contract MetaCoin {
	mapping (address => uint256) balances;

	event Transfer(address indexed _from, address indexed _to, uint256 _value);

	constructor() public {
		balances[tx.origin] = 100000;
	}

	function sendCoin(address receiver, uint256 amount, address sender) public returns(bool sufficient) {
		if (balances[sender] < amount) return false;
		balances[sender] -= amount;
		balances[receiver] += amount;
		emit Transfer(sender, receiver, amount);
		return true;
	}


	function getBalance(address addr) public view returns(uint256) {
		return balances[addr];
	}
}

contract Loan is MetaCoin {
    mapping (address => uint256) private loans;
     
    event Request(address indexed _from, uint256 P, uint R, uint T, uint256 amt);
    
    address private Owner;
    address private LoanFrom;
    uint256 private LoanP; 
    uint private    LoanR;     
    uint private    LoanTakenAt;

    modifier isOwner() {
	require(msg.sender == Owner, "Only Owner allowed to use this function");
        _;
    }
    
    constructor() public {
        Owner = msg.sender;
    }
    
    // Fill up the following function definitions and also try to justify why some functions are pure and some are view and some are none, in your README.md
    
    function getCompoundInterest(uint256 principle, uint rate, uint time) public pure returns(uint256) {
    		// Anyone should be able to use this function to calculate the amount of Compound interest for given P, R, T        // A good way to prevent overflows will be to typecast principle, rate and the big number divider suggested in the above blogs as uint256 variables, just use uint256 R = rate;
	      // Time in seconds
          uint256 totPay;
          uint n=time / 31556952; uint nsec= time % 31556952;
	  if( n > 0 ) {
             totPay = ABDKMath64x64.mulu( ABDKMath64x64.pow( 
      			ABDKMath64x64.add ( ABDKMath64x64.fromUInt (1), ABDKMath64x64.divu (rate, 10**18)), n),
    				principal);
         }
         if( nsec > 0 ) {
                ABDKMath64x64.add ( 
		  ABDKMath64x64.divu(
                    ABDKMath64x64.mulu( principal, 
		      ABDKMath64x64.mulu( rate, nsec ) ), 3155695200 ), toPay );
        } 
        return toPay;
    }
    
    function reqLoan(uint256 principle, uint rate, uint time) public returns(bool correct) {
        uint256 toPay = getCompoundInterest(principle, rate, time);
        // A creditor uses this function to request the Owner to settle his loan, and the amount to settle is calculated using the inputs.
        // Also emit the Request event after succesfully adding to the mapping, and return true. Return false if adding to the mapping failed (maybe the user entered a float rate, there were overflows and toPay comes to be lesser than principle, etc.
	LoanP = principle; LoanR = rate; LoanTakenAt = now;
	emit Request( Owner, principle, rate, time, toPay);
    }
    
    function getOwnerBalance() public view returns(uint256) {
				// use the getBalance function of MetaCoin contract to view the Balance of the contract Owner.
	return getBalance( Owner );
	}

    // implement viewDues and settleDues which allow *ONLY* the owner to *view* and *settle* his loans respectively. They take in the address of a creditor as arguments. viewDues returns a uint256 corresponding to the due amount, and does not modify any state variables. settleDues returns a bool, true if the dues were settled and false otherwise. Remember to set the the pending loan to 0 after settling the dues.
    // use sendCoin function of MetaCoin contract to send the coins required for settling the dues.

    function viewDues() public isOwner view returns(uint256)  {
	return getCompoundInterest( LoanP, LoanR, now - LoanTakenAt);
	}

    function settleDues(address fromCred ) public isOwner returns(bool) {
	uint256 toPay = viewDues();
	if( getOwnerBalance() > toPay ) {
		if( sendCoin( LoanFrom, toPay, Owner ) == true ) {
                     LoanFrom = 0; LoanP = 0; LoanR = 0; LoanTakenAt = 0;
                     return true;
                }
                else return false;
	}
	else return false;
    }
}
