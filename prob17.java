public class Main{
	static String ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	static String elevens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	static String tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	public static String getString(int n){
		if( n < 10 )return ones[n];
		if( n > 10 && n < 20)return elevens[n%10];
		if( n < 100 )return tens[n/10] + ones[n%10];
		if( n < 1000 ){
			return ones[n/100]+ "hundred"+ ((n%100 != 0)?"and":"") + getString( n % 100 );
		}
		else return "onethousand";
	}	
	public static void main(String args[]){
		int c = 0;
		for(int i=1;i<=1000; i++ )
			c+=getString(i).length();
			
			
		System.out.println(c);
		
	}
}

/*
10 * [ 9*(1-9) + (11-20) + 10*(20-90) + ten ] + 100*(1-9 + 9*hundred + 9*and) - 10*and + "one thousand"

10 * ( 9*a + b + 10*c - 9*3 ) + 100* (a + 9*7 + 27) - 30 + 11
10* (9*36 + 67 + 490 - 27) + 100* (36 + 63 + 27) - 19
10*(324 + 530) + 100 * (126) - 19
(85400) + 12600 - 19

*/

