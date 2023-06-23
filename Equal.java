
import java.io.*;
public class Equal
{	
	static File f1;
	static File f2;
	Equal(File f1, File f2){
		this.f1=f1;
		this.f2=f2;
	}
    boolean isEqual()throws IOException {
    	BufferedReader reader1 = new BufferedReader(new FileReader(f1.getPath()));
        
        BufferedReader reader2 = new BufferedReader(new FileReader(f2.getPath()));
         
        String line1 = reader1.readLine();
         
        String line2 = reader2.readLine();
         
        boolean areEqual = true;
         
        int lineNum = 1;
         
        while (line1 != null || line2 != null)
        {
            if(line1 == null || line2 == null)
            {
                areEqual = false;
                 
                break;
            }
            else if(! line1.equalsIgnoreCase(line2))
            {
                areEqual = false;
                 
                break;
            }
             
            line1 = reader1.readLine();
             
            line2 = reader2.readLine();
             
            lineNum++;
        }
        reader1.close();
        
        reader2.close();
        return areEqual;
    }
}
