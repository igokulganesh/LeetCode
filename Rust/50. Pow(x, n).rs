pub fn my_pow(x: f64, n: i32) -> f64 {
    if n == 0 {
        return 1.0;
    }

    let temp = Self::my_pow(x, n / 2);

    if n % 2 == 0 {
        return temp * temp;
    } else {
        if n > 0 {
            return x * temp * temp;
        } else {
            return 1.0 / x * temp * temp;
        }
    }
}
