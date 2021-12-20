import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.UIManager.*;

public class TempConverter {
    private JTextField celsiusField;
    private JTextField fahrField;
    private JPanel panelMain;
    private JTextField kelvinField;
    private JTextField rankineField;

    private static Temperature temperature;

    public TempConverter() {
        temperature = new Temperature();

        celsiusField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
//                    fahrField.setText(String.format("%s", Converter.toFahr(
//                            Double.parseDouble(celsiusField.getText()))));
                    temperature.setCelsius(Double.parseDouble(
                            celsiusField.getText()
                    ));
                    updateAllFields();
                } catch (NumberFormatException err) {
//                    fahrField.setText("ERROR");
                    errorAllFields();
                    System.out.println(err.getMessage());
                }
            }
        });
        fahrField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
//                    celsiusField.setText(String.format("%s", Converter.toCelsius(
//                            Double.parseDouble(fahrField.getText()))));
                    temperature.setFahrenheit(Double.parseDouble(
                            fahrField.getText()
                    ));
                    updateAllFields();
                } catch (NumberFormatException err) {
//                    celsiusField.setText("ERROR");
                    errorAllFields();
                    System.out.println(err.getMessage());
                }
            }
        });
        kelvinField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    temperature.setKelvin(Double.parseDouble(
                            kelvinField.getText()
                    ));
                    updateAllFields();
                } catch (NumberFormatException err) {
                    errorAllFields();
                    System.out.println(err.getMessage());
                }
            }
        });
        rankineField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    temperature.setRankine(Double.parseDouble(
                            rankineField.getText()
                    ));
                    updateAllFields();
                } catch (NumberFormatException err) {
                    errorAllFields();
                    System.out.println(err.getMessage());
                }
            }
        });
    }

    /**
     * Call after updating the Temperature object.
     */
    public void updateAllFields() {
        celsiusField.setText(String.format("%.4f", temperature.getCelsius()));
        fahrField.setText(String.format("%.4f", temperature.getFahrenheit()));
        kelvinField.setText(String.format("%.4f", temperature.getKelvin()));
        rankineField.setText(String.format("%.4f", temperature.getRankine()));
    }

    public void errorAllFields() {
        String errorMessage = "ERROR";

        celsiusField.setText(errorMessage);
        fahrField.setText(errorMessage);
        kelvinField.setText(errorMessage);
        rankineField.setText(errorMessage);
    }

    public static void main(String[] args) {
        activateNimbus();
        JFrame frame = new JFrame("Temperature Converter");
        frame.setContentPane(new TempConverter().panelMain);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    private static void activateNimbus() {
        try {
            for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            System.err.printf("Unable to set Nimbus theme - using default " +
                    "(ugly!) theme.\n" +
                    "Error: %s", e);
        }
    }
}
