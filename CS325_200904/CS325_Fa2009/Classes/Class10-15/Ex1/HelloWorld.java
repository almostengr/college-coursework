import java.util.Scanner;

/**
*This class is called HelloWorld and it just says HelloWorld
*for the most part. It's pretty boring.
*/


public class HelloWorld{

	/**
	*This is the HelloWorld constructor.  It's pretty neat, it's just a
	*constructor.
	*/
	public HelloWorld(){
		System.out.println("Give me a number:" );
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		for(int i = 1; i <= n; i++){
			System.out.println(" " + i);
		}
	}

	NotPublic np = new NotPublic();

	/**
	* Function f returns the string concatted to itself some number of
	* times. 
	* @param a This is an integer that specifies how many times to concat
	* @param b  
	*/

/*	
	public HelloWorld(){
		System.out.println("Hello World, from a new instance");
	}
*/

	public static void main(String args[]){
	
		HelloWorld hw = new HelloWorld();

/*
		for(int i = 0; i < 10; i++){
			HelloWorld hw = new HelloWorld();
		}	
*/


/*
		System.out.println("Hello World");
	
		System.out.println(args.length);

		for(int i = 0; i < args.length; i++){
			System.out.println(args[i] + " ");
		}
*/

	}

	class NotPublic{
		NotPublic(){
			System.out.println("I'm not public");
		}
	}
}
