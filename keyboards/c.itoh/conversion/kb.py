import os
import json

data = None
with open('/Users/ahmed/DEV/qmk_firmware/keyboards/c.itoh/conversion/data.json') as f_in:
  data = json.load(f_in)

for item in data["keyboard"]["keys"]:
    col = item["col"]
    if item["col"] == 10:
      item["col"] = 4
    elif item["col"] == 11:
      item["col"] = 5
    elif item["col"] == 12:
      item["col"] = 6
    elif item["col"] == 13:
      item["col"] = 7
print(json.dumps(data))
