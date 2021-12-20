public class Converter {
    public static double toFahr(double celsius) {
        return (celsius * 9 / 5) + 32;
    }

    public static double toCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }

    public static double toKelvin(double celsius) {
        return celsius + 273.15;
    }

    public static double toRankine(double fahrenheit) {
        return fahrenheit + 459.67;
    }
}
