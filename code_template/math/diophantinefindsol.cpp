// ax + by = c
// if c not divisible by gcd(a, b), then no ans
// else x = x0 * c / g, y = y0 * x / g

// If need to iterate answer
// x += b / g
// y += a / g

// Corner case
// if a = b = 0 and c = 0. Infinite ans exists, else no ans.

// Minimizing x + y
// If a < b, then minimize k
// If b < a, then maximize k
// if b == a, any solution would be same