public class AccelerometerSensor {
    int[] accelerations;

    public AccelerometerSensor() {
        accelerations = new int[3];
        for (int i = 0; i < 3; i++) {
            accelerations[i] = -1;
        }
    }

    public AccelerometerSensor(int[] values) {
        setValues(values);
    }

    public AccelerometerSensor(int x, int y, int z) {
        this();
        setValues(x, y, z);
    }

    public void setValues(int[] values) {
        accelerations = values;
    }

    public void setValues(int x, int y, int z) {
        accelerations[0] = x;
        accelerations[1] = y;
        accelerations[2] = z;
    }

    public int[] getValues() {
        return accelerations;
    }

    public String toString() {
        return "Accelerometer X: " + accelerations[0] + " Y: " + accelerations[1] + " Z: " + accelerations[2];
    }
}
