//Lab-Assignment#2
//This program simulates a simple computer simpletron. It takes command line arguments from the user and performs them.
import java.util.Scanner;//import Scanner classs

public class Simpletron 
{
    private static int accumulator = 0;// a registor in which information is put
    private static int instructionCounter = 1;// a variable that keeps track of the current instruction being performed
    private static int operationCode = 0; //the leftmost two digits of the instruction indicates the current operation in excecution.
    private static int operand = 0; // the rightmost two digits of the instruction being performed currently
    private static int[] instructionRegister;// an array that stores the current instruction to be performed
    private static final int READ = 10;//initialization
    private static final int WRITE = 11;//initialization
    private static final int LOAD = 20;//initialization
    private static final int STORE = 21;//initialization
    private static final int ADD = 30;//initialization
    private static final int SUBTRACT = 31;//initialization
    private static final int DIVIDE = 32;//initialization
    private static final int MULTIPLY = 33;//initialization
    private static final int BRANCH = 40;//initialization
    private static final int BRANCHNEG = 41;//initialization
    private static final int BRANCHZERO = 42;//initialization
    private static final int HALT = 43;//initialization

	//execute application
	public static void main(String[] args)
	{
		int[] memory = new int[100];// A placeholder for the program that has maximum 100 space 
		int[] instructionRegister = new int[args.length];// the size of array instructionRegister is equivalent to args.length
		                                                 //args.length depends on the number of command line arguments
				
		// input command line arguments and store them in an array instructionRegister
		for(int i = 0; i < args.length; i++)
		{
			instructionRegister[i] = Integer.parseInt(args[i]);// processing
		}
		
		System.out.printf("\n\t\t\t   %s\n","**Welcome to Simpletron**");
				
		// for loop continues until all the instructions stored in the array instructionRegister are performed		
		for(int i = 0; i < instructionRegister.length;i++)
		{
			operationCode = instructionRegister[i]/100;// processing
			operand = instructionRegister[i]%100;// processing
			 
			//Display the names and contents of Registors , memory ;operation being performed and the current instruction. 
		    System.out.printf("\n REGISTERS: \n accumulator \t\t%+05d\n instructionCounter  \t   %02d\n instructionRegister \t%+04d\n",accumulator,instructionCounter,instructionRegister[i]);//system prompt
			System.out.printf(" operationCode    \t   %02d\n operand \t\t   %02d\n",operationCode,operand);//system prompt
		    System.out.printf("\n MEMORY:\n");//system prompt
			
			//to specify exact memory location from 0 to 9
			System.out.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",0,1,2,3,4,5,6,7,8,9);  
			
			// for loop displays the contents of the memory
			for(int j = 0;j < memory.length; j++)
			{
				//if statement displays the left index of memory location (0,10,20,30...)
				if(j%10 == 0)
				{
					System.out.println();//print new line
					System.out.printf(" %02d",j);// System prompt
				}
				System.out.printf(" %+05d  ",memory[j]);// Display the memory array (0-100)				
			}// end of for loop		
			
			System.out.println();//print new line
			
			// switch takes Operation Code as an argument which it performs
			switch(operationCode)
			{
				case READ:// Displays a prompt and Read a word from the keyboard into a specific location in memory
				        Scanner input = new Scanner ( System.in );// creates a new Scanner object input
						
				        System.out.print ( "\nPlease Enter a whole number (positive or negative): " );// System prompt
				        memory [operand] = input.nextInt ();// place the result in the specified memory location
				        
						instructionCounter++;// increment				
				break;
				case WRITE:// write a specific location in memory to the output screen
				        
						System.out.println ("\nThe result of the operation is " + memory [operand] );// System prompt
				        
						instructionCounter++;// increment				
				break;
				case LOAD:// load a word from a specific location into the accumulator 
			         	
						accumulator = memory[operand];// processing
				        
						instructionCounter++;// increment
				break;
				case STORE:// Store a word from the accumulator into a specific location in memory
				        
						memory[operand] = accumulator;// processing
				        
						instructionCounter++;// increment
				break;
				case ADD://Add a word from a specific location in memory to the word in the accumulator 
				         //( leave the result in the accumulator)
				        
						accumulator += memory[operand];// processing

			           	instructionCounter++;// increment
				break;
				case SUBTRACT:// Subtract a word from a specific location in memory from the 
				              // word in the accumulator ( leave the result in the accumulator )
				        
						accumulator -= memory[operand];// processing
				        
						instructionCounter++;// increment
				break;
				case DIVIDE:// Divide a word from a specific location in memory into the 
			                // word in the accumulator ( leave the result in the accumulator )
				        
						accumulator /= memory[operand];// processing
				        
						instructionCounter++;// increment				
				break;
				case MULTIPLY:// Multiply a word from a specific location in memory by the
			                  // word in the  accumulator ( leave the result in the accumulator )
				        
						accumulator *= memory[operand];// processing
				        
						instructionCounter++;// increment
				break;
				case BRANCH:// branch to a specific location in memory
				        
						instructionCounter = operand;// processing
				break;
				case BRANCHNEG:// branch to a specific location in memory if the accumulator is negative
				        
						// if statement checks whether the accumulator is negative
						if(accumulator < 0)
				        {
					          instructionCounter = operand;// processing
				        }
				break;
				case BRANCHZERO:// branch to a specific location if the accumulator is zero
				        
						// if statement checks whether the value of accumulator is equivalent to 0
						if(accumulator == 0)
				          {
					          instructionCounter = operand;// processing
				          }
				break;
				case HALT:// Halt. The program has completed its tasks
				        
						System.out.printf("\n\t\t\t   %s\n","* Simpletron execution terminated *");//System prompt
				break;				
			}//end of switch 
			
	    }// end of for loop
		
	}// end of method main		
	
}