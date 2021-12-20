/**
 * Output in the scientific unit of your choice.
 * Stores internally as Kelvin form.
 * Depends on Converter class :(
 */
public class Temperature {
    private double kelvin;

    public void setKelvin(double kelvin) {
        this.kelvin = kelvin;
    }

    public double getKelvin() {
        return kelvin;
    }

    public double getCelsius() {
        return kelvin - 273.15;
    }

    public void setCelsius(double celsius) {
        kelvin = celsius + 273.15;
    }

    public double getFahrenheit() {
        return Converter.toFahr(getCelsius());
    }

    public void setFahrenheit(double fahrenheit) {
        kelvin = Converter.toKelvin(Converter.toCelsius(fahrenheit));
    }

    public double getRankine() {
        return Converter.toRankine(Converter.toFahr(getCelsius()));
    }

    public void setRankine(double rankine) {
        kelvin = getFahrenheit() - 459.67;
    }
}