import csv
import requests


with open("vgdb_2016.csv") as csv_file:
 csv_reader = csv.reader(csv_file, delimiter=',')
 line_count = 0
 for row in csv_reader:
    if line_count >= 11:
        break
    if line_count == 0:
        pass
    else:
        print(row[2])
        response = requests.get(row[2])
        with open(f"imgs/sample_img_{line_count}.jpg", "wb") as f:
            f.write(response.content)
    line_count += 1



