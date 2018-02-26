cc_binary(
	name = "hz2pinyin_test",
	srcs = [
		"main.cc",
	],
	deps = [
		':hz2pinyin',
		'//Common/Base:Base'
	],
	optimize = ['O3'],
	extra_cppflags = [
		'-fno-omit-frame-pointer',
		'-Wl,--eh-frame-hdr',
		'-Wno-reorder',
		'-std=c++11',	
	]
)

cc_library(
	name = "hz2pinyin",
	srcs = [
        "hz2pinyin.cc",
	],
	deps = [
		'//Common/Base:Base',
        '//Common/Util/Encode:encodeUtil',
	],
	optimize = ['O3'],
	extra_cppflags = [
		'-fno-omit-frame-pointer',
		'-Wl,--eh-frame-hdr',
		'-Wno-reorder',
		'-std=c++11',	
	]
)