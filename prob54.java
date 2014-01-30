/*
This looks straightforward, only representation needs to be given thought.
One obvious way would be to assign a unique number to each card and proceed accordingly.
This is lengthy. :/

Alright, this code is too bad for me. I'm starting all over again.
Will monitor packs individually. Storing player number against each card didn't help.

After glancing through Mathblog's solution and reading the comments the guy made on this problem, all I can say is this will be pretty boring if done the obvious way.
Time to put our thinking caps on.

Let's try to think what can be thought about this problem.
The data we can store would include:
1. The number of cards of each type and value a player has
2. The number of pairs the pair with highest value for each player.
3. Triplet and it's value.
4. Cards sorted by value.
5. Quadruplet if it exists.
6. If all cards are consecutive.

One strategy could be:
1. Count and sort the cards of each type a player has.
2. Count the number of cards of each value a player has.
3. If there are pairs, triplets or quadruplets, find the ones with greatest value.(triplets and quadruplets can't be more than one)
4. If there are no pairs, triplets or quads, check if the cards are consecutive.

Considering all this, these are the variables we'll need:
Four arrays of max length 5
variables to store: values of two pairs, one triplet, one quad
flag to determine if values are consecutive
^ all this per player
Let's dive in!

Brrrr. Java.
*/
import java.util.*;
public class Player{
	int H[], D[], S[], C[];
	public Player(String hands){
		String arr[] = hands.split(" ");
		for(int i = 0; i < arr.length; i++){
			char c = arr[i].charAt(arr[i].length() - 1);//for card type
			if(arr[i].charAt(0) < 58){// it's a number
				arr[i].charAt(0) == '1')
			}


		}

	}

}