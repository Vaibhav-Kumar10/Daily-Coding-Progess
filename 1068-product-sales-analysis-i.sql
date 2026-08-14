SELECT product_name, year, price
FROM Sales
NATURAL JOIN Product;
-- ON sales.product_id = Product.product_id;