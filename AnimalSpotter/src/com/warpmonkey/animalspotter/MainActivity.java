package com.warpmonkey.animalspotter;

import android.support.v4.app.FragmentManager;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends FragmentActivity {
	private static final int ITEMS = 10;
	 FragAdapter mAdapter;
	 ViewPager mPager;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	
	public static class FragAdapter extends FragmentPagerAdapter {
		
		 public FragAdapter(FragmentManager fragmentManager) {
			 super(fragmentManager);
		 }
		 
		 @Override
		 public int getCount() {
			 return ITEMS;
		 }
		 
		 @Override
		 public Fragment getItem(int position) {
//			 switch (position) {
//			 	case 0: // Fragment # 0 - This will show image
//			 		return ImageFragment.init(position);
//			 	case 1: // Fragment # 1 - This will show image
//			 		return ImageFragment.init(position);
//			 	default:// Fragment # 2-9 - Will show list
//			 		return TruitonListFragment.init(position);
//			 }
			 return null;
		 }
	 }
}


