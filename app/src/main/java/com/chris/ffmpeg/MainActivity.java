package com.chris.ffmpeg;

import android.os.Bundle;
import android.view.SurfaceView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("bigNN-player");
    }
    private final String PATH = "rtmp://58.200.131.2:1935/livetv/hunantv";


    private SurfaceView mSurfaceView;
    private FFmpegPlayer mFmpegPlayer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mSurfaceView = (SurfaceView) findViewById(R.id.tv_sv);
        mFmpegPlayer = new FFmpegPlayer();
        mFmpegPlayer.setDataPath(PATH);
        mFmpegPlayer.setSurfaceView(mSurfaceView);


    }


    public native String stringFromJNI();

    @Override
    protected void onResume() {
        super.onResume();
        mFmpegPlayer.prepare();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mFmpegPlayer.stop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mFmpegPlayer.release();
    }
}
