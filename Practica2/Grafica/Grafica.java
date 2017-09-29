package grafica;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import javax.swing.JFrame;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.DefaultCategoryDataset;

public class Grafica
{
    //creacion de los objetos que van a generar la grafica
    DefaultCategoryDataset Datos = new DefaultCategoryDataset();
    JFreeChart Grafica;
    public void generarGrafica()
    {
        File archivo = null;
        FileReader lectura = null;
        BufferedReader buffer = null;
        try
        {
            //se intenta abrir el archivo y crear el BufferedReader
            archivo = new File ("Poblacion.txt");
            lectura = new FileReader (archivo);
            buffer = new BufferedReader(lectura);
            // Lectura del fichero
            String linea;
            int index1;
            int index2;
            int actitud;
            String posicion;
            String poblacion;
            while((linea=buffer.readLine())!=null)
            {
                //insersion de datos
                index1=linea.indexOf(" ");
                actitud=Integer.parseInt(linea.substring(0, index1));
                index2=linea.indexOf(" ", index1 + 1);
                poblacion=linea.substring(index1 + 1, index2);
                posicion=linea.substring(index2+1, linea.length());
                Datos.addValue(actitud, poblacion, posicion);
            }         
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        finally
        {
            // cerramos el archivo
            try
            {                    
                if( null != lectura )
                {   
                    lectura.close();     
                }                  
            }
            catch (Exception e2)
            { 
                e2.printStackTrace();
            }
        }
        //Creacion de la Grafica
        Grafica = ChartFactory.createLineChart("Actitud de los Individuos de la Población",
                "No. de Individuo", "Actitud", Datos, PlotOrientation.VERTICAL, true, true, 
                false);
        //Generación de la ventana
        ChartPanel Panel = new ChartPanel(Grafica);
        JFrame Ventana = new JFrame(" Actitud de Población");
        Ventana.getContentPane().add(Panel);
        Ventana.pack();
        Ventana.setVisible(true);
        Ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
}
