/**
 * 
 */
package ejercicios;

import java.io.IOException;
import java.io.InputStream;

/**
 * @author rcm93
 *
 */
public class Ejercicio1_15 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Process p = new ProcessBuilder("CMD", "/C", "DIR").start();
//En linux
//Process p = new ProcessBuilder("bash", "-c", 
//"ls").start();

		try {
			InputStream is = p.getInputStream();
			// mostramos en pantalla caracter a caracter
			int c;
			while ((c = is.read()) != -1)
				System.out.print((char) c);
			is.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		// COMPROBACIÓN DE ERROR - 0 bien - 1 mal
		int exitVal;
		try {
			exitVal = p.waitFor();
			System.out.println("Valor de Salida: " + exitVal);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

}
