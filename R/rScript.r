# Load necessary libraries
library(openxlsx)
library(ggplot2)

# Generate 4 rolls of a 6-sided die
set.seed(123) # For reproducibility
rolls <- sample(1:6, 4, replace = TRUE)

# Create a data frame
df <- data.frame(Roll = 1:4, Value = rolls)

# Create a ggplot chart
p <- ggplot(df, aes(x = factor(Roll), y = Value)) +
    geom_bar(stat = "identity") +
    labs(title = "4 Rolls of a 6-Sided Die", x = "Roll Number", y = "Value")

# Save the chart to a temporary file
temp_file <- tempfile(fileext = ".png")
ggsave(temp_file, plot = p, width = 6, height = 4)

# Create a new workbook and add a worksheet
wb <- createWorkbook()
addWorksheet(wb, "Rolls")

# Write the data frame to the worksheet
writeData(wb, "Rolls", df)

# Insert the chart into the worksheet
insertImage(wb, "Rolls", temp_file, startRow = 6, startCol = 2, width = 6, height = 4)

# Save the workbook to a file
saveWorkbook(wb, "rolls_with_chart.xlsx", overwrite = TRUE)

# Clean up the temporary file
unlink(temp_file)