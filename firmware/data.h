static ImageInfo sadImageInfo = {57, 23, 0, 4};
const char sadImageData[] = {
	0xc0,0x3e,0x22,0x22,0x22,0x22,0x22,0x22,
	0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,
	0x22,0x22,0x22,0x22,0x22,0x3e,0xc0,0xff,
	0x00,0x00,0x80,0x42,0x42,0x42,0x42,0x42,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x82,0x00,0x00,0xff,0xff,0x00,
	0x00,0xff,0x00,0xa0,0x40,0xa1,0x01,0x02,
	0x12,0x0a,0x12,0x02,0x01,0xa0,0x40,0xa0,
	0x00,0xff,0x00,0x00,0xff,0x0f,0x10,0x20,
	0x23,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
	0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
	0x23,0x20,0x10,0x0f,
};

static ImageInfo floppyImageInfo = {29, 27, 2, 4};
const char floppyImageData[] = {
	0xfe,0x01,0x01,0x01,0xff,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0xff,0x01,
	0x01,0x01,0xfe,0xff,0x00,0x00,0x00,0x1f,
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x20,0x1f,0x00,0x00,0x00,0xff,0xff,0x00,
	0x00,0x00,0x00,0x00,0xfc,0x02,0x02,0xf2,
	0x0a,0x0a,0x0a,0xf2,0x02,0x02,0x02,0x02,
	0x02,0x02,0xfc,0x00,0x00,0x00,0x00,0x00,
	0xff,0x00,0x01,0x02,0x04,0x04,0x04,0x07,
	0x04,0x04,0x04,0x05,0x05,0x05,0x04,0x04,
	0x04,0x04,0x04,0x04,0x04,0x07,0x04,0x04,
	0x04,0x04,0x04,0x03,
};

static ImageInfo smileImageInfo = {57, 23, 1, 4};
const char smileImageData[] = {
	0xc0,0x3e,0x22,0x22,0x22,0x22,0x22,0x22,
	0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,
	0x22,0x22,0x22,0x22,0x22,0x3e,0xc0,0xff,
	0x00,0x00,0x80,0x42,0x42,0x42,0x42,0x42,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x82,0x00,0x00,0xff,0xff,0x00,
	0x00,0xff,0x00,0x00,0x00,0x60,0x02,0x01,
	0x01,0x79,0x09,0x01,0x02,0x60,0x00,0x00,
	0x00,0xff,0x00,0x00,0xff,0x0f,0x10,0x20,
	0x23,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
	0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
	0x23,0x20,0x10,0x0f,
};

static ImageInfo balloonImageInfo = {4, 50, 1, 4};
const char balloonImageData[] = {
	0x00,0x80,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x80,0x00,
	0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xff,0x80,0x00,0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xfe,0x03,0x01,0x01,0x02,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
	0x04,0x04,0x04,0x04,0x02,0x01,0x00,0x00,
};

static ImageInfo timeImageInfo = {62, 17, 2, 3};
const char timeImageData[] = {
	0x00,0x00,0x80,0x40,0x20,0x20,0x10,0x10,
	0x10,0x10,0x10,0x20,0x20,0x40,0x80,0x00,
	0x00,0x7c,0x83,0x00,0x00,0x01,0x02,0x04,
	0x08,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x83,0x7c,0x00,0x01,0x02,0x04,0x08,0x08,
	0x10,0x10,0x17,0x10,0x10,0x08,0x08,0x04,
	0x02,0x01,0x00,
};

static ImageInfo upImageInfo = {0, 5, 0, 1};
const char upImageData[] = {
	0x02,0x06,0x0e,0x06,0x02,
};

static ImageInfo downImageInfo = {0, 5, 0, 1};
const char downImageData[] = {
	0x80,0xc0,0xe0,0xc0,0x80,
};

static ImageInfo face0ImageInfo = {15, 54, 0, 6};
const char face0ImageData[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xf0,0xf0,0xf0,0xf0,
	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7e,0x7e,0x7e,0x7e,
	0x7e,0x7e,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x7e,
	0x7e,0x7e,0x7e,0x7e,0x7e,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xe0,0xe0,0xe0,0xe0,
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x07,
	0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,
};

static ImageInfo face1ImageInfo = {15, 54, 0, 6};
const char face1ImageData[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xf0,0xf0,0xf0,0xf0,
	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7e,0x7e,0x7e,0x7e,
	0x7e,0x7e,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x7e,
	0x7e,0x7e,0x7e,0x7e,0x7e,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xe0,0xe0,0xe0,0xe0,
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x07,
	0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0x03,0x03,
	0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,
	0x03,0x03,0x03,0x03,
};

static ImageInfo face2ImageInfo = {15, 54, 0, 6};
const char face2ImageData[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xe0,0xe0,0xe0,0xf8,0xf8,0xf8,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xf8,0xf8,0xf8,0xe0,
	0xe0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
	0x07,0x07,0x0f,0x0f,0x0f,0x3f,0x3f,0x3f,
	0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,
	0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,
	0x3f,0x3f,0x0f,0x0f,0x0f,0x07,0x07,0x07,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xe0,0xe0,0xe0,0xe0,
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x07,
	0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,
};

static ImageInfo face3ImageInfo = {15, 54, 0, 6};
const char face3ImageData[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xe0,
	0xe0,0xf8,0xf8,0xf8,0xfe,0xfe,0xfe,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
	0xfe,0xf8,0xf8,0xf8,0xe0,0xe0,0xe0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7f,0x7f,0x7f,0x7f,
	0x7f,0x7f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,
	0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,
	0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,
	0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x7f,
	0x7f,0x7f,0x7f,0x7f,0x7f,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xe0,0xe0,0xe0,0xe0,
	0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x07,
	0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,
	0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,
};

