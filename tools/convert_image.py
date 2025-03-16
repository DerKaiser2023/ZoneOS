from PIL import Image
import numpy as np

# Load the image
image_path = "image.png"
image = Image.open(image_path)

# Resize image to 320x240 (matching framebuffer resolution)
image = image.resize((32, 240))

# Convert to raw pixel data (RGB format)
image_data = np.array(image.convert("RGB"))

# Convert to 32-bit values (assuming 0x00RRGGBB format for framebuffer)
image_array = []
for row in image_data:
    for pixel in row:
        r, g, b = pixel
        color = (r << 16) | (g << 8) | b  # Convert to 32-bit color format
        image_array.append(color)

# Generate C header file content
boot_image_h = f"""#ifndef BOOT_IMAGE_H
#define BOOT_IMAGE_H

#define IMAGE_WIDTH  320
#define IMAGE_HEIGHT 240

const unsigned int boot_image_data[IMAGE_WIDTH * IMAGE_HEIGHT] = {{
    {', '.join(map(str, image_array))}
}};

#endif
"""

# Save the generated header file
with open("boot_image.h", "w") as f:
    f.write(boot_image_h)

print("Generated boot_image.h successfully!")