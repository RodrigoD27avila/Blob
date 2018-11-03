package br.furb.poo2.exercicios

import java.io.File;
import java.io.FileInputStream;

class Copy {
	private boolean byteByte;


	public Copy(boolean byteByte) {
		setByteByte(byteByte);
	}

	public void copy(File src, File dst) {
		if (src.exists() && dst.exists() && dst.isDirectory()) {
		} else {
			throw new
		}
	}

	public void setByteByte(boolean byteByte) {
		this.byteByte = byteByte;
	}

	public boolean isByteByte() {
		return this.byteByte;
	}
}
