# データの読み込み
data <- read.csv(file = "1_7.txt", header = TRUE)
# データの確認
head(data)
length(data)

# Scatter plot
plot(data$x, data$y)

# Linear Regression
result <- lm(y ~ x, data)
summary(result)
