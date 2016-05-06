package com.example.kinjal.foryou;

import android.content.Context;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Adapter;
import android.widget.ImageView;
import android.widget.LinearLayout;

public class HappyMoments extends AppCompatActivity {

    ViewPager viewPager;
    HappySwipeAdapter adapter;

    MediaPlayer mediaPlayer;

    int length;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_happy_moments);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        mediaPlayer = MediaPlayer.create(HappyMoments.this, R.raw.sooraj_ki_bahon);
        mediaPlayer.setLooping(true);
        mediaPlayer.setVolume(100, 100);
        mediaPlayer.start();

        viewPager = (ViewPager)findViewById(R.id.viewPager);
        adapter = new HappySwipeAdapter(this);
        viewPager.setAdapter(adapter);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mediaPlayer.pause();
        length = mediaPlayer.getCurrentPosition();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mediaPlayer.seekTo(length);
        mediaPlayer.start();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        mediaPlayer.seekTo(length);
        mediaPlayer.start();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mediaPlayer.release();
    }
}

class HappySwipeAdapter extends PagerAdapter {

    private int[] imageResource = {R.drawable.happy1, R.drawable.happy2, R.drawable.happy3, R.drawable.happy4, R.drawable.happy5, R.drawable.happy6, R.drawable.happy7, R.drawable.happy8, R.drawable.happy9, R.drawable.happy10, R.drawable.happy11, R.drawable.happy12, R.drawable.happy13, R.drawable.happy14, R.drawable.happy15, R.drawable.happy16};
    private Context ctx;
    private LayoutInflater layoutInflater;

    ImageView imageView;
    View item_view;

    public HappySwipeAdapter(Context ctx)
    {
        this.ctx = ctx;
    }
    @Override
    public int getCount() {
        return imageResource.length;
    }

    @Override
    public boolean isViewFromObject(View view, Object object) {
        return (view == (LinearLayout)object);
    }

    @Override
    public Object instantiateItem(ViewGroup container, int position) {
        layoutInflater = (LayoutInflater)ctx.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        item_view = layoutInflater.inflate(R.layout.swipe_layout, container, false);
        imageView = (ImageView)item_view.findViewById(R.id.image_view);
        imageView.setImageResource(imageResource[position]);
        imageView.setId(position);
        container.addView(item_view);
        return item_view;
    }

    @Override
    public void destroyItem(ViewGroup container, int position, Object object) {
        container.removeView((LinearLayout) object);
    }
}
